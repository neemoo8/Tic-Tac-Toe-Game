object UNIT: TUNIT
  Left = 629
  Top = 213
  Align = alCustom
  Caption = 'WELCOME TO TIC TAC TOE'
  ClientHeight = 467
  ClientWidth = 687
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Button1: TButton
    Left = 160
    Top = 88
    Width = 361
    Height = 81
    Caption = 'LOGIN  '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -60
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 200
    Width = 361
    Height = 81
    Caption = 'SIGNUP  '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -60
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 112
    Top = 320
    Width = 481
    Height = 81
    Align = alCustom
    Caption = ' FORGOT PASSWORD '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -47
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
end
