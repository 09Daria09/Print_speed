#include "Level.h"
#include"Text.h"
Level* Level::ptr = NULL;

Level::Level(void)
{
	ptr = this;
}

void Level::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

Level::~Level(void)
{
}

BOOL Level::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	return TRUE;
}


void Level::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	srand(NULL(time));
	HWND hText = GetParent(GetDlgItem(hwnd, IDC_EDIT2));
	if (id == IDCANCEL2)
	{
		EndDialog(hwnd, 0);
	}
	if (id == IDC_LEVEL_1)
	{
		int j = 7;
		for (int i = 0; i < 200; i++)
		{
			
			if (rand() % 2)
			{
				str[i] = 'f';
			}
			else
			{
				str[i] = 'j';
			}
			if (i == j)
			{
				str[i] = ' ';
				j += 1 + rand() % 11;
			}
			if (str[i] == ' ' && str[i + 1] == ' ' || str[i] == ' ' && str[i - 1] == ' ')
			{
				str[i] = 'f';
			}
		}
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_1);

	}
	if (id == IDC_LEVEL_2)
	{
		_tcscpy_s(str, TEXT("ggggggg hhhhhh gg gg hh gg ghhhh hhhghhhhgh gggghg hhhhhhgh gh hg gggggh hhhhhg ghghgfff fff jjj hgf jjhgf fghj jjjhgf hhh gggghg hghgh jjjjfffh hjhhhhjjjj ggggfffff fggfg hgjfhjgh ghfjhg jhjhgf hgfj"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_2);
	}
	if (id == IDC_LEVEL_3)
	{
		_tcscpy_s(str, TEXT("ddddd dd dk kk kkk kkkddd ddkdkkk dkdkdk dkdk fdddf jjjkkk gfggggffff hhhjjjjhh hkkhhkhhfd dhhhdd hffffhfh gfgjjdjk kddkd dkfjk fjdkh fjgh fjdhgh jdfkjfh fjfdkfdk fffjjhghgh ghghghkjdjf kdkdjfdkfkfkg"));
		SetWindowText(hText, str); 
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_4)
	{
		_tcscpy_s(str, TEXT("sssssss aaaaaaa lllla lllalla alal sslslaslla s as als alsaslksss djhgj ajhahah ah aja kak ala sjjsjs djs sjdj ldldfllg lgg shasha sahs sah hshsf gf fasd sad flag glkd glas asdf fljs sj fjla lad flla"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_5)
	{
		_tcscpy_s(str, TEXT("tttt yy yyyty tytyt jff ftft jyjy tjtjt yfyf fyf yfyfyjt ktktk sysyysy sya sdsa ydyf syfjt dad adadadah ta taa aata ta tads tag tags taj yayad yaff yaffs yah Yahata yakyakka yaks yald Yalta yayyays a"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_6)
	{
		_tcscpy_s(str, TEXT("rrru uuru rurur uurur rrut tyuur fufu fu dudus aujjrjr rfds drjghrh sry adult adultly adults adust darg dargah dark darkly raff raffs raft rafts	rag	raga ultra ultradry	ultrafast ultras usual usually"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_7)
	{
		_tcscpy_s(str, TEXT("ccvcvvcv vvvcv bnccbb vvvbvbnbv ncvnbfbhb hfvb nfngnfb ckck vd asc vdfbjnhgktnvyc cabbalah cachucha callbacks bull	bullbat brush brushy brusk gradually graduals naughts navvy vastly vary untruthfully"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_8)
	{
		_tcscpy_s(str, TEXT("xxxx mxm xmxm zmzxmz xmx zmxmz xm eie iedidjejm xdjs mxnzz azsx zingers zingier xanthene xanthenes vinculum vinculums verdancy unnecessaries universalizability undifferentiated climbing climbs egg eg"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_9)
	{
		_tcscpy_s(str, TEXT("qqqwwqw wqwp ooppopo opoqpq qpwowpwdjd jwjwjqj papw pwf proqws bpr typ owpq That evening when i came down to say goodnight i overheard uncle pat talking with auntie pat they both looked glum as they "));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
	if (id == IDC_LEVEL_10)
	{
		_tcscpy_s(str, TEXT("techniques which are used to win customers include coupons samples money back competitions etc many of these techniques are over a hundred years old new promotion techniques are not often developed"));
		SetWindowText(hText, str);
		EndDialog(hwnd, IDC_LEVEL_3);
	}
}

BOOL CALLBACK Level::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
