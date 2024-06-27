object SIGN_UP: TSIGN_UP
  Left = 0
  Top = 0
  Caption = 'SIGN UP'
  ClientHeight = 327
  ClientWidth = 442
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 48
    Top = 104
    Width = 93
    Height = 21
    Caption = 'Username:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 184
    Width = 100
    Height = 21
    Caption = 'password:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object user_edit: TEdit
    Left = 112
    Top = 139
    Width = 241
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object pass_edit: TEdit
    Left = 112
    Top = 227
    Width = 241
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object login: TButton
    Left = 176
    Top = 272
    Width = 105
    Height = 33
    Caption = 'sign up '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = loginClick
  end
end
