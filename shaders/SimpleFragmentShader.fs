#version 120
void main(void) {
  //gl_FragColor[0] = 1.0;
  //gl_FragColor[1] = 0.0;
  //gl_FragColor[2] = 1.0;
  gl_FragColor[0] = gl_FragCoord.x/640.0; //r
  gl_FragColor[1] = gl_FragCoord.y/480.0; //g
  gl_FragColor[2] = 0.5; //b
  float step = floor(gl_FragCoord.y / 16);

  gl_FragColor[3] = mod(step, 2) == 0 ? 1.0 : 0.5;
}
