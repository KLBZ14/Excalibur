#version 330 core

in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

struct DirLight
{
	vec3 direction;
	vec3 color;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
struct PointLight
{
	vec3 position;
	vec3 color;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};
struct SpotLight
{
	vec3 position;
	vec3 color;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 
  
uniform Material material;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

uniform vec3 viewPos;


vec3 calculateDirLight(DirLight light);
vec3 calculatePointLight(PointLight light);


void main()
{
	vec3 DirectionalLight = calculateDirLight(dirLight);
	vec3 PointLight = calculatePointLight(pointLight);
	FragColor = vec4(DirectionalLight + PointLight, 1.0);
}

vec3 calculateDirLight(DirLight light)
{
	//ambient lighting
	vec3 ambient = material.ambient * light.ambient * light.color;

	//diffuse lighting
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.direction);
	float diff = max(dot(norm, -lightDir), 0.0);
	vec3 diffuse = diff * material.diffuse * light.diffuse * light.color;

	//specular lighting
	vec3 reflectDir = reflect(lightDir, norm);
	vec3 viewDir = normalize(viewPos - FragPos);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128.0);
	vec3 specular = spec * light.specular * material.specular * light.color;  

	vec3 result = ambient + diffuse + specular;
	return result;
}

vec3 calculatePointLight(PointLight light)
{
	//calculate attenuation
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); 
	
	//ambient lighting
	vec3 ambient = material.ambient * light.ambient * light.color * attenuation;

	//diffuse lighting
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * material.diffuse * light.diffuse * light.color * attenuation;

	//specular lighting
	vec3 reflectDir = reflect(-lightDir, norm);
	vec3 viewDir = normalize(viewPos - FragPos);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128.0);
	vec3 specular = spec * light.specular * material.specular * light.color * attenuation;  

	vec3 result = ambient + diffuse + specular;
	return result;
}