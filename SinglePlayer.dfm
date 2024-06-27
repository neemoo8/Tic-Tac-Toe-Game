object single_player: Tsingle_player
  Left = 0
  Top = 0
  Caption = 'PLAY WITH AI'
  ClientHeight = 440
  ClientWidth = 504
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LabelStatus: TLabel
    Left = 216
    Top = 130
    Width = 3
    Height = 15
  end
  object Button10: TButton
    Left = 393
    Top = 399
    Width = 103
    Height = 33
    Caption = 'EXIT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button10Click
  end
  object Button1: TButton
    Left = 1
    Top = 16
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonClick
  end
  object Button3: TButton
    Tag = 2
    Left = 343
    Top = 16
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonClick
  end
  object Button4: TButton
    Tag = 3
    Left = -8
    Top = 151
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonClick
  end
  object Button5: TButton
    Tag = 4
    Left = 168
    Top = 151
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonClick
  end
  object Button6: TButton
    Tag = 5
    Left = 343
    Top = 151
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonClick
  end
  object Button7: TButton
    Tag = 6
    Left = -8
    Top = 272
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonClick
  end
  object Button8: TButton
    Tag = 7
    Left = 168
    Top = 272
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonClick
  end
  object Button9: TButton
    Tag = 8
    Left = 343
    Top = 272
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = ButtonClick
  end
  object Button2: TButton
    Tag = 1
    Left = 160
    Top = 16
    Width = 153
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = ButtonClick
  end
  object historyButton: TButton
    Left = 8
    Top = 399
    Width = 120
    Height = 33
    Caption = 'HISTORY '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    OnClick = historyButtonClick
  end
end
