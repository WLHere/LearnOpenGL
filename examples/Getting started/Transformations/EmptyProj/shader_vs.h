//
//  shader_vs.h
//  EmptyProj
//
//  Created by wenlong bai on 2021/2/5.
//

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTextureCoord;

out vec3 ourColor;
out vec2 TextureCoord;

uniform mat4 transform;

void main() {
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aColor;
    TextureCoord = vec2(aTextureCoord.x, aTextureCoord.y);
}
