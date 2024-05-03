#version 440

layout(location=0) in vec2 qt_TexCoord0;

layout(location=0) out vec4 fragColor;

layout(std140, binding=0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    
    float frequency;
    float amplitude;
    float time;
} ubuf;

layout(binding=1) uniform sampler2D source;

void main() {
    vec2 pulse = sin(ubuf.time - ubuf.frequency * qt_TexCoord0);
    vec2 coord = qt_TexCoord0 + ubuf.amplitude * vec2(pulse.x, -pulse.x);
    fragColor = texture(source, coord) * ubuf.qt_Opacity;
}
