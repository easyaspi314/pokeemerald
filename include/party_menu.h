#ifndef GUARD_PARTY_MENU_H
#define GUARD_PARTY_MENU_H

enum
{
    AILMENT_NONE,
    AILMENT_PSN,
    AILMENT_PRZ,
    AILMENT_SLP,
    AILMENT_FRZ,
    AILMENT_BRN
};

bool8 pokemon_has_move(struct Pokemon *, u16);
void sub_81B58A8(void);
void DoWallyTutorialBagMenu(void);
u8 pokemon_ailments_get_primary(u32 status);
u8 *GetMonNickname(struct Pokemon *mon, u8 *dst);
u8 GetCursorSelectionMonId(void);
bool8 FieldCallback_Teleport(void);

#endif // GUARD_PARTY_MENU_H
