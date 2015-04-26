for (int x = -spanX; x < spanX; x++) {
    for (int y = -spanY; y < spanY; y++) {
        glm::mat4 Model = glm::translate(identity, glm::vec3(x * objectSpan, 0, y * objectSpan));

        Model = glm::rotate(Model, rotation, glm::vec3(0.f, 1.f, 0.f));
        glm::mat4 MVP = Projection * View * Model;

        ShaderProgram.setUniformMatrix(MatrixID, GL_FALSE, &MVP[0][0]);
        ShaderProgram.setVertexAttrib(vertexPositionID, ShaderProgram.vertexbuffer, 3, GL_FLOAT, GL_ARRAY_BUFFER);
        ShaderProgram.setVertexAttrib(vertexColorID, ShaderProgram.colorbuffer, 3, GL_FLOAT, GL_ARRAY_BUFFER);

        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
        counter++;
    }
}