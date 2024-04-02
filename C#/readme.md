#C# 학습하기

이 저장소에는 `dbConNet`이라는 간단한 C# 애플리케이션이 포함되어 있습니다. 이 애플리케이션은 Windows Form 애플리케이션으로, C#의 다양한 기능을 보여줍니다.

## dbConNet 디자인

![화면 캡처 2024-04-02 172355](https://github.com/sika7492/inteledge/assets/154478957/05047311-d429-4d74-9742-dfdb47ed8474)

## dbConNet 기능

1. **확인 버튼 (`bnConfirm_Click`)**: 버튼을 클릭하면 텍스트 박스에 "환영합니다.\r\n여기는 C# 확인용 텍스트입니다."라는 메시지가 표시됩니다.
2. **제거 버튼 (`bnRemove_Click`)**: 버튼을 클릭하면 텍스트 박스의 내용이 제거되고, "텍스트가 제거되었습니다."라는 메시지가 표시됩니다.
3. **체크박스 (`ckbOpt10_CheckedChanged`, `ckbOpt20_CheckedChanged`)**: 체크박스를 선택하면 해당 과일 이름이 텍스트 박스에 추가되고, 체크를 해제하면 해당 과일 이름이 텍스트 박스에서 제거됩니다.
4. **라디오 버튼 (`rbRed_CheckedChanged`, `rbGreen_CheckedChanged`, `rbBlue_CheckedChanged`, `rbNp_CheckedChanged`, `rbEq_CheckedChanged`, `rbSp_CheckedChanged`)**: 라디오 버튼을 선택하면 해당 색상 또는 위치가 텍스트 박스에 표시됩니다.
5. **콤보 박스 (`cmbDv_SelectedIndexChanged`, `cmbDic_SelectedIndexChanged`)**: 콤보 박스에서 항목을 선택하면 해당 항목이 텍스트 박스에 표시됩니다.
