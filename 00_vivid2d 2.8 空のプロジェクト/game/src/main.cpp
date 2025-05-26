
/*!
 *  @file       main.cpp
 *  @brief      �G���g���[�|�C���g
 *  @author     Kazuya Maruyama
 *				Toshihito Ohashi
 *  @date       2023/05/08
 *  @version    1.1
 *
 *  Copyright (c) 2013-2023, Kazuya Maruyama. Toshihito Ohashi. All rights reserved.
 */

#include "vivid.h"
#include"math.h"

constexpr double PI = 3.14159265358979323846;

vivid::Vector2 AbePos = { 100.0f,100.0f };
float Speed = 5;
vivid::Rect rect = { 0,0,64,64 };
vivid::Vector2  Anchor = { 32,32 };
float angle = 0.0f;
vivid::Vector2 Scale = { 1.0f,1.0f };

/*!
 *  @brief      �`��֐�
 */
void
Display(void)
{
    /*vivid::Point Pt = vivid::mouse::GetCursorPos();

    float dx = Pt.x - (AbePos.x + 32);
    float dy = Pt.y - (AbePos.y + 32);

    float rag = atan2(dy, dx);*/

    float rag = angle * 180 / 3.14;

    if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
    {
        if (90 < (int)rag % 360 && (int)rag % 360 < 270)
        {
            //vivid::DrawTexture("data\\abe.png", vivid::Vector2(100, 200));
            Scale.y = -1;
        }
        else
        {
            //vivid::DrawTexture("data\\abe.png",vivid::Vector2(100,100));
            Scale.y = 1;
        }
        AbePos.y -= Speed;

        if (90 < (int)rag % 360 && (int)rag % 360 < 270)
        {
            angle += 0.05;
        }
        else if (90 == (int)rag % 360 || (int)rag % 360 == 270)
        {
            angle += 0;
        }
        else
        {
            angle += -0.05;
            }
        

    }
    if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::A))
    {
        if (90 < (int)rag % 360 && (int)rag % 360 < 270)
        {
            //vivid::DrawTexture("data\\abe.png", vivid::Vector2(100, 200));
            Scale.y = -1;
        }
        else
        {
            //vivid::DrawTexture("data\\abe.png",vivid::Vector2(100,100));
            Scale.y = 1;
        }
        AbePos.x -= Speed;
            if (180 < (int)rag % 360 && (int)rag % 360 < 360)
            {
                angle += -0.05;
            }
            else
            {
                angle += 0.05;
            }


    }
    if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
    {
        if (90 < (int)rag % 360 && (int)rag % 360 < 270)
        {
            //vivid::DrawTexture("data\\abe.png", vivid::Vector2(100, 200));
            Scale.y = -1;
        }
        else
        {
            //vivid::DrawTexture("data\\abe.png",vivid::Vector2(100,100));
            Scale.y = 1;
        }
        AbePos.y += Speed;
            if (90 < (int)rag % 360 && (int)rag % 360 < 270)
            {
                angle += -0.05;
            }
            else if (90 == (int)rag % 360 || (int)rag % 360 == 270)
            {
                angle += 0;
            }
            else
            {
                angle += 0.05;
            }

    }
    if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::D))
    {
        if (90 < (int)rag % 360 && (int)rag % 360 < 270)
        {
            //vivid::DrawTexture("data\\abe.png", vivid::Vector2(100, 200));
            Scale.y = -1;
        }
        else
        {
            //vivid::DrawTexture("data\\abe.png",vivid::Vector2(100,100));
            Scale.y = 1;
        }
        AbePos.x += Speed;
            if (0 < (int)rag % 360 && (int)rag % 360 < 180)
            {
                angle += -0.05;
            }
            else
            {
                angle += 0.05;
            }

    }

    //if (90 < (int)rag % 360 && (int)rag % 360 < 270)
    //{
    //    //vivid::DrawTexture("data\\abe.png", vivid::Vector2(100, 200));
    //    Scale.x = -1;
    //}
    ////if ((0 <= (int)rag % 360 && (int)rag % 360 < 90) || (270 < (int)rag % 360 && (int)rag % 360 <= 359))
    //else
    //{
    //    //vivid::DrawTexture("data\\abe.png",vivid::Vector2(100,100));
    //    Scale.x = 1;
    //}

    vivid::DrawTexture("data\\abe.png", AbePos, 0xffffffff, rect, Anchor,Scale, angle);

    vivid::DrawText(40, std::to_string(angle), vivid::Vector2(0, 0));
}

/*!
 *  @brief      ���C���֐�
 *
 *  @param[in]  hInst       �C���X�^���X�n���h��
 *  @param[in]  hPrevInst   Win16����̈╨
 *  @param[in]  lpCmdLine   �R�}���h���C��������
 *  @param[in]  nCmdShow    �E�B���h�̕\�����@
 *
 *  @return     ���C���֐��̐���
 */
int WINAPI
WinMain( _In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow )
{
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;

    // vivid���C�u����������
    vivid::Initialize( hInst );

    // �X�V/�`��֐��o�^
    vivid::DisplayFunction( Display );

    // �Q�[�����[�v
    vivid::MainLoop( );

    // vivid���C�u�������
    vivid::Finalize( );
}
