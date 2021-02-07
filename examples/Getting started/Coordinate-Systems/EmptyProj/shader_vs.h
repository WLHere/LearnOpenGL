//
//  shader_vs.h
//  EmptyProj
//
//  Created by wenlong bai on 2021/2/5.
//

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTextureCoord;

out vec2 TextureCoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

void main() {
    gl_Position = projectionMat * viewMat * modelMat * vec4(aPos, 1.0);
    TextureCoord = vec2(aTextureCoord.x, aTextureCoord.y);
}
