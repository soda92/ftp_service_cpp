#include <ncftp.h>

int main()
{
    FTPLibraryInfo li;
    FTPConnectionInfo ci;
    FTPInitLibrary(&li);
    FTPInitConnectionInfo(&li, &ci, kDefaultFTPBufSize);
    strcpy(ci.user, "user");
    strcpy(ci.pass, "12345");
    strcpy(ci.host, "127.0.0.1");
    ci.port = 2222;
    int result = 0;
    if ((result = FTPOpenHost(&ci)) < 0)
    {
        fprintf(stderr, "Cannot open host: %s.\n", FTPStrError(result));
        exit(1);
    }
    FTPLineList fileList;
    int err = 0, i = 0;
    FTPLinePtr lp;
    err = FTPListToMemory(&ci, "/pub", &fileList, "");
    if (err == kNoErr)
    {
        for (lp = fileList.first, i = 0; lp != NULL; lp = lp->next)
        {
            ++i;
            printf("item #%d: %s\n", i, lp->line);
        }
    }
    DisposeLineListContents(&fileList);
}