#pragma once
#include "stdafx.h"

class TextBlock
{
public :
	TextBlock(const char* _text)
	{
		text = _text;
		cout << "TextBlock �������Դϴ�\n";
	}
	~TextBlock()
	{
		text.clear();	
		cout << "TextBlock �Ҹ����Դϴ�\n";
	}

	const char& operator[](std::size_t position) const
	{
		cout << "TextBlock ��� operator �Դϴ�\n";
		return text[position];
	}

	//char& operator[] (std::size_t position)			// Old Version
	//{
	//	cout << "TextBlock ���� operator �Դϴ�\n";
	//	return text[position];
	//}

	char operator[] (std::size_t position)				// New Version
	{
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}
private :
	std::string text;
};

class CTextBlock
{
public :
	CTextBlock(const char* _text)
	{
		memcpy(pText, _text, strlen(_text) + 1);
	}
	~CTextBlock()
	{
		delete[] pText;
	}

	char& operator[](size_t position) const	// ��������(�׷��� ��Ʈ����
	{										// ������� �־ ���Ǵ�)
		return pText[position];				// operator[]�� ����
	}
	
	size_t CTextBlock::length() const
	{
		if (!lengthIsValid)
		{
			textlength = strlen(pText);
			lengthIsValid = true;
		}
		return textlength;
	}
private :
	char *pText;
	mutable size_t textlength;		// ��Ʈ���� �����(bitwise constness)�� �����ϴ� Ű������ mutable
	mutable bool lengthIsValid;
};

//TextBlock tb("Hello");
//cout << tb[0] << endl;

//const TextBlock ctb("World");
//cout << ctb[0] << endl;
//
//tb[0] = 'x';
//ctb[0] = 'x'; // ���� --> ��ȯ Ÿ���� �ٸ���.

//const CTextBlock cctb("Hello");
//char *pc = &cctb[0];
//*pc = 'J';

//char ch[128];