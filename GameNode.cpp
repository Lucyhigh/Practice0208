#include "Stdafx.h"
#include "GameNode.h"
#include <Locale.h>

HRESULT GameNode::init(void)
{
	//�Լ��� ���������� ����Ǿ����� �˸��� S_OK ��ȯ
	//Success_ok
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;


	if (managerInit)
	{	
		//Ÿ�̸� �ʱ�ȭ
		SetTimer(_hWnd, 1, 10, NULL);
		
		//Ű�Ŵ��� �ʱ�ȭ
		KEYMANAGER->init();

		//���� ��� �ʱ�ȭ
		RND->init();

		//�̹����Ŵ��� �ʱ�ȭ
		IMAGEMANAGER->init();

		//�ӽ� ����Ŵ��� �ʱ�ȭ 
		TEMPSOUNDMANAGER->init();
	}

	return S_OK;
}

void GameNode::release(void)
{
	if (_managerInit)
	{
		// ������ ����(���丮���� �ѱ۷� �˻��ϱ� ���� �ʿ�) - ������ ��� ���� �߰��� ��.
		setlocale(LC_ALL, "Korean"); // LC_ALL : OS�� ����� �ѱ�(Korean) ������ ��� �����´�. 

		//Ÿ�̸� ����
		KillTimer(_hWnd, 1);

		//Ű�Ŵ��� �̱��� ����
		KEYMANAGER->releaseSingleton();

		// ������� �̱��� ����
		RND->releaseSingleton();

		// �̹����Ŵ��� ����
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();

		// ��Ʈ�Ŵ��� �̱��� ���� 
		FONTMANAGER->releaseSingleton();

		//�ӽ� ����Ŵ��� �̱��� ����
		TEMPSOUNDMANAGER->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);
}

void GameNode::update(void)
{
	//���ΰ�ħ
	//���۸��� �߰��Ǹ� ����� �ʿ��ϴ�
	InvalidateRect(_hWnd, NULL, FALSE);
}

void GameNode::render(void)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT imessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;		//�ڵ�DC
	PAINTSTRUCT ps;	//����Ʈ����ü

	switch (imessage)
	{
	case WM_TIMER:
		this->update();
		break;
	case WM_CREATE:  //������
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->render();
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		//20211230 ���콺��ǥ 
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			break;

		case VK_RIGHT:
			break;

		case VK_UP:
			break;

		case VK_DOWN:
			break;

		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0); //esc������ �Ҹ��� �θ���
			break;
		}
		InvalidateRect(hWnd, NULL, false);  // ȭ���� ��� ��¦�Ÿ��ٸ� false �� �����ؾ��� (���� ������������)
		break;

	case WM_DESTROY:    //�Ҹ���
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, imessage, wParam, lParam);
	return LRESULT();
}
