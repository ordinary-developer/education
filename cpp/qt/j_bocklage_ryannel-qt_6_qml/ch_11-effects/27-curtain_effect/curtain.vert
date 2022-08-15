#version 440

layout(location=0) in vec4 qt_Vertex;
layout(location=1) in vec2 qt_MultiTexCoord0;

layout(location=0) out vec2 qt_TexCoord0;
layout(location=1) out float shade;

layout(std140, binding=0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    
    float topWidth;
    float bottomWidth;
    float width;
    float height;
    float amplitude;
} ubuf;

out gl_PerVertex { 
    vec4 gl_Position;
};
 
void main() {
    qt_TexCoord0 = qt_MultiTexCoord0;

    vec4 shift = vec4(0.0, 0.0, 0.0, 0.0);
    float swing = (ubuf.topWidth - ubuf.bottomWidth) * (qt_Vertex.y / ubuf.height);
    shift.x = qt_Vertex.x * (ubuf.width - ubuf.topWidth + swing) / ubuf.width;

    shade = sin(21.9911486 * qt_Vertex.x / ubuf.width);
    shift.y = ubuf.amplitude * (ubuf.width - ubuf.topWidth + swing) * shade;

    gl_Position = ubuf.qt_Matrix * (qt_Vertex - shift);

    shade = 0.2 * (2.0 - shade) * ((ubuf.width - ubuf.topWidth + swing) / ubuf.width);
}
