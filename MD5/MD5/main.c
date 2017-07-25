#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "global.h"
#include "md5.h"


int FileList(wchar_t *path)
{
	HANDLE hSrch;
	WIN32_FIND_DATA wfd;
	BOOL bResult = TRUE;
	wchar_t drive[_MAX_DRIVE];
	wchar_t dir[_MAX_DIR];
	wchar_t filename[_MAX_FNAME];
	wchar_t fileext[_MAX_EXT];

	wchar_t newpath[MAX_PATH];
	wchar_t filepath[MAX_PATH];

	wchar_t md5[50];
	FILE *fp;

	int nSameFile = 0;
	//printf("\n검색 경로 = %s\n", path);
	hSrch = FindFirstFile(path, &wfd);
	if (hSrch == INVALID_HANDLE_VALUE) {
		return 1;
	}
	_wsplitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_DIR, filename, _MAX_FNAME, fileext, _MAX_EXT);
	while (bResult) {
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (wcscmp(wfd.cFileName, L".") && wcscmp(wfd.cFileName, L"..")) {
				wsprintf(filepath, L"%s%s%s\\*.*", drive, dir, wfd.cFileName);
				FileList(filepath);
			}
		}
		else {
			memset(filepath, 0, MAX_PATH);
			memset(md5, 0, 50);
			swprintf_s(filepath, MAX_PATH, L"%s%s%s", drive, dir, wfd.cFileName);
			_wsplitpath_s(filepath, drive, _MAX_DRIVE, dir, _MAX_DIR, filename, _MAX_FNAME, fileext, _MAX_EXT);
			if (_wfopen_s(&fp, filepath, L"rb") != 0)
				return 1;
			MDFile_FP(fp, md5);
			wprintf(L"%s : %s%s%s\n", md5, drive, dir, wfd.cFileName);
			fclose(fp);

			nSameFile = 1;
			swprintf_s(newpath, MAX_PATH, L"%s%s%s%s", drive, dir, md5, fileext);
			while (_wrename(filepath, newpath) != 0)
			{
				swprintf_s(newpath, MAX_PATH, L"%s%sSameFileNo-%04d_%s%s", drive, dir, nSameFile, md5, fileext);
				nSameFile++;
			}
		}
		bResult = FindNextFile(hSrch, &wfd);
	}
	FindClose(hSrch);

	return 0;
}

void main()
{
	wchar_t Path[MAX_PATH] = L"C:\\Users\\TUNA\\Downloads";
	wcscat_s(Path, MAX_PATH, L"\\*.*");
	FileList(Path);
}