#version 330 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
    float constant;
    float linear;
    float quadratic;
};

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

out vec4 FragColor;

void main() {
    vec3 texColor = vec3(texture(material.diffuse, TexCoord));
    
    vec3 ambient = light.ambient * texColor;
    
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - norm);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = light.diffuse * diff * texColor;
    
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0), material.shininess);
    vec3 specular = light.specular * (spec * vec3(texture(material.specular, TexCoord)));
    
    float distance = length(light.position - FragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * distance * distance);
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    vec3 result = ambient + diffuse + specular;
    
    FragColor = vec4(result, 1.0f);
}

