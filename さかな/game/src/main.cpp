//aaaaaaaaaaaaa
/*!
 *  @file       main.cpp
 *  @brief      �G���g���[�|�C���g
 *  @author     Kazuya Maruyama
 *				Toshihito Ohashi
 *  @date       2023/05/08
 *  @version    1.0
 *
 *  Copyright (c) 2013-2023, Toshihito Ohashi. All rights reserved.
 */

#include "vivid.h"
#include"Player/Player.h"

#include"feed_manager/feed_manager.h"

 Player player;
 Feed_manager feed;

/*!
 *  @brief      �`��֐�
 */
void
Display(void)
{
    player.Update();
    feed.Update(player.Get_Player_center_pos(), player.Get_player_mouth_radius());
    player.Draw();
    feed.Draw();
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

    player.Initialize();// �v���C���[�̏�����
    feed.Initialize();
    // �X�V/�`��֐��o�^
    vivid::DisplayFunction( Display );

    // �Q�[�����[�v
    vivid::MainLoop( );

    // vivid���C�u�������
    vivid::Finalize( );

    player.Finalize();//�v���C���[�̉��
}
