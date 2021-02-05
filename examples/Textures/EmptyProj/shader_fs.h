//
//  shader_fs.h
//  EmptyProj
//
//  Created by wenlong bai on 2021/2/5.
//

#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TextureCoord;

uniform sample2D texture1;

void main() {
    FragColor = texture(texture1, TextureCoord);
}


