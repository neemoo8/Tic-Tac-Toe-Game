object Multi_player: TMulti_player
  Left = 0
  Top = 0
  Caption = 'Have a nice time'
  ClientHeight = 425
  ClientWidth = 526
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 155
    Height = 21
    Caption = 'PLAY 1 WILL BE X '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 8
    Top = 32
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonClick
  end
  object Button2: TButton
    Tag = 1
    Left = 184
    Top = 32
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonClick
  end
  object Button3: TButton
    Tag = 2
    Left = 360
    Top = 32
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonClick
  end
  object Button4: TButton
    Tag = 3
    Left = 8
    Top = 160
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonClick
  end
  object Button5: TButton
    Tag = 4
    Left = 184
    Top = 160
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonClick
  end
  object Button6: TButton
    Tag = 5
    Left = 360
    Top = 160
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonClick
  end
  object Button7: TButton
    Tag = 6
    Left = 8
    Top = 288
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonClick
  end
  object Button8: TButton
    Tag = 7
    Left = 184
    Top = 288
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonClick
  end
  object Button9: TButton
    Tag = 8
    Left = 360
    Top = 288
    Width = 129
    Height = 97
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 8
    OnClick = ButtonClick
  end
  object Button10: TButton
    Left = 421
    Top = 391
    Width = 97
    Height = 40
    Caption = 'EXIT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = Button10Click
  end
  object Button12: TButton
    Left = 8
    Top = 391
    Width = 105
    Height = 40
    Caption = 'HISTORY    '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 10
    OnClick = Button12Click
  end
end
