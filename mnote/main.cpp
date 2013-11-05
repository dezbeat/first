#include "mainwindow.h"
#include <QApplication>
#include <string.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    struct tm *t;
          char str[100];
          time_t ltime;
          time(&ltime);
          t = localtime(&ltime);
          strcpy(str,asctime(t));

   /* for(int i = 0; i<3; i++)
    {
        QFile::copy("test.txt", "//home//endru//edu//testing//file2_"+str+".txt");
    }*/
    MainWindow w;
    w.show();

    return a.exec();
}
