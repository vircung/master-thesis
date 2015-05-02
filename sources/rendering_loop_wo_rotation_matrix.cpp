glm::mat4 VP = Projection * View;
glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotation, glm::vec3(0.f, 1.f, 0.f));
for (int x = -spanX; x < spanX; x++) {
    for (int y = -spanY; y < spanY; y++) {
        glm::mat4 Model = glm::translate(identity, glm::vec3(x * objectSpan, 0, y * objectSpan));

        ShaderProgram.setUniformMatrix(RmatrixID, GL_FALSE, &rotationMatrix[0][0]);
        ShaderProgram.setUniformMatrix(MmatrixID, GL_FALSE, &Model[0][0]);
        ShaderProgram.setUniformMatrix(VPmatrixID, GL_FALSE, &VP[0][0]);

        ShaderProgram.setVertexAttrib(vertexPositionID, ShaderProgram.vertexbuffer, 3, GL_FLOAT, GL_ARRAY_BUFFER);
        ShaderProgram.setVertexAttrib(vertexColorID, ShaderProgram.colorbuffer, 3, GL_FLOAT, GL_ARRAY_BUFFER);

        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
        counter++;
    }
}