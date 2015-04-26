#version 130

in vec3 vertexPosition;
in vec3 vertexColor;
out vec3 fragmentColor;

uniform mat4 VPmatrix;
uniform mat4 Mmatrix;

void main() {
    gl_Position = VPmatrix * Mmatrix * vec4(vertexPosition, 1);
    fragmentColor = vertexColor;
}