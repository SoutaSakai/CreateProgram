
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
#include"playermanager/Player/Player.h"
#include"playermanager/playermanager.h"
#include"playermanager/Charactermanager/CharacterID.h"

//playermanager pm;

static const int MaxPlyer = 4;

CHARACTER_ID UseCharacter[MaxPlyer][3] = 
{   {CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
    {CHARACTER_ID::ELSCTRICEEL,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
    {CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
    {CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}
};



/*!
 *  @brief      �`��֐�
 */
void
Display(void)
{
    playermanager::GetInstance().Update();
    playermanager::GetInstance().Draw();
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

    for (int i = 0; i < MaxPlyer; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            playermanager::GetInstance().GetUseCharacter(UseCharacter[i][k], i, k);
        }
    }

    playermanager::GetInstance().Initialize(MaxPlyer);
   
    // �X�V/�`��֐��o�^
    vivid::DisplayFunction( Display );

    // �Q�[�����[�v
    vivid::MainLoop( );

    // vivid���C�u�������
    vivid::Finalize( );
}
