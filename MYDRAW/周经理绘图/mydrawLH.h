
// �ܾ����ͼ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ܾ����ͼApp:
// �йش����ʵ�֣������ �ܾ����ͼ.cpp
//

class C�ܾ����ͼApp : public CWinApp
{
public:
	C�ܾ����ͼApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ܾ����ͼApp theApp;