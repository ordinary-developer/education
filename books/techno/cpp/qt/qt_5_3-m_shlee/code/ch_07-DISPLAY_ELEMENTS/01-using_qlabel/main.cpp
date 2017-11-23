#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{"<h1><center>QLabel - HTML Demo</center></h1>"
                 "<h2><center>Image</center></h2>"
                 "<center><img border=\"0\" src=\":/image.jpg\"></center>" 
                 "<h2><center>List</center></h2>"
                 "<ol><li>One</li>"
                 "    <li>Two</li>"
                 "    <li>Three</li>"
                 "</ol>"
                 "<h2><center>font style</center></h2>"
                 "<center><font color=red>"
                 "    <b>Bold</b>, <i>Italic</i>, <u>underline</u>"
                 "</font></center>"
                 "<h2><center>Table</center></h2>"
                 "<center> <table>"
                 "    <tr bgcolor=#ff00ff>"
                 "        <td>1,1</td><td>1,2</td><td>1,3</td><td>1,4</td>"
                 "    </tr>"
                 "    <tr bgcolor=yellow>"
                 "        <td>2,1</td><td>2,2</td><td>2,3</td><td>2,4</td>"
                 "    </tr>"
                 "    <tr bgcolor=#00f000>"
                 "        <td>3,1</td><td>3,2</td><td>3,3</td><td>3,4</td>"
                 "    </tr>"
                 "</table></center>"
                 };                 
    label.show();

    return app.exec();
}
