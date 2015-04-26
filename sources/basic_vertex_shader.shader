in vec3 vertexPosition;
in vec3 vertexColor;
out vec3 fragmentColor;

uniform mat4 MVP;

void main() {
    gl_Position = MVP * vec4(vertexPosition, 1);
    fragmentColor = vertexColor;
}