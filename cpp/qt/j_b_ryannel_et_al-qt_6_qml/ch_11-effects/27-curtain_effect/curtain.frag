#version 440

layout(location=0) in vec2 qt_TexCoord0;
layout(location=1) in float shade;

layout(location=0) out vec4 fragColor;

layout(std140, binding=0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    
    float topWidth;
    float bottomWidth;
    float width;
    float height;
    float amplitude;
} ubuf;

layout(binding=1) uniform sampler2D source;

void main() {
    highp vec4 color = texture(source, qt_TexCoord0);
    color.rgb *= 1.0 - shade;
    fragColor = color;
}
