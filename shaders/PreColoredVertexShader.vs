#version 120
attribute vec2 coord2d;
attribute vec3 vertexColor;
varying vec3 fragmentColor;
void main(void) {
  gl_Position = vec4(coord2d, 0.0, 1.0);
  fragmentColor = vertexColor;
}
