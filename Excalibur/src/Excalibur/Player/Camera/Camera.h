#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>


// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

// Default camera values
static float YAW = -90.0f;
static float PITCH = 0.0f;
static float SPEED = 2.5f;
static float SENSITIVITY = 0.1f;
static float ZOOM = 45.0f;



class Camera
{
public:
    
    // camera Attributes
    static glm::vec3 cameraPosition;
    static glm::vec3 Front;
    static glm::vec3 WorldFront;
    static glm::vec3 Up;
    static glm::vec3 Right;
    static glm::vec3 WorldUp;
    // euler Angles
    static float Yaw;
    static float Pitch;
    // camera options
    static float MovementSpeed;
    static float MouseSensitivity;
    static float Zoom;

    static float lastX;
    static float lastY;
    static bool firstMouse;

    void setupCamera(GLFWwindow* window, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH, glm::vec3 worldFront = glm::vec3(0.0f, 0.0f, -1.0f));
    
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(cameraPosition, cameraPosition + Front, Up);
    }

    static void updateValues(Camera_Movement direction, float deltaTime);
    void runEventGather(GLFWwindow* window, float deltaTime);
private:
    static void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up and worldFront vectors
        Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up = glm::normalize(glm::cross(Right, Front));
        WorldFront = glm::normalize(glm::cross(WorldUp, -Right));
    }



    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

    // glfw: whenever the mouse scroll wheel scrolls, this callback is called
    // ----------------------------------------------------------------------
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};
