#version 120
varying vec3 fragmentColor;
void main(void) {
  gl_FragColor = vec4(fragmentColor.x, fragmentColor.y, fragmentColor.z, 1.0);
}
