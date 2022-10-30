#include "Camera.h"





// camera Attributes
glm::vec3 Camera::cameraPosition;
glm::vec3 Camera::Front;
glm::vec3 Camera::WorldFront;
glm::vec3 Camera::Up;
glm::vec3 Camera::Right;
glm::vec3 Camera::WorldUp;
// euler Angles
float Camera::Yaw;
float Camera::Pitch;
// camera options
float Camera::MovementSpeed;
float Camera::MouseSensitivity;
float Camera::Zoom;


float Camera::lastX = 700;
float Camera::lastY = 450;
bool Camera::firstMouse = true;


void Camera::setupCamera(GLFWwindow* window, glm::vec3 position, glm::vec3 up, float yaw, float pitch, glm::vec3 worldFront)
{
    Front = glm::vec3(0.0f, 0.0f, -1.0f);
    MovementSpeed = SPEED;
    MouseSensitivity = SENSITIVITY;
    Zoom = ZOOM;
    cameraPosition = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    WorldFront = worldFront;

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    updateCameraVectors();
}

void Camera::updateValues(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        cameraPosition -= WorldFront * velocity;
    if (direction == BACKWARD)
        cameraPosition += WorldFront * velocity;
    if (direction == LEFT)
        cameraPosition -= Right * velocity;
    if (direction == RIGHT)
        cameraPosition += Right * velocity;
    if (direction == UP)
        cameraPosition += WorldUp * velocity;
    if (direction == DOWN)
        cameraPosition -= WorldUp * velocity;
}




void Camera::runEventGather(GLFWwindow* window, float deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        updateValues(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        updateValues(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        updateValues(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        updateValues(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        updateValues(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        updateValues(DOWN, deltaTime);
}





void Camera::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (Pitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}
