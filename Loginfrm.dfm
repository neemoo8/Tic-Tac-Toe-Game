object LoginForm: TLoginForm
  Left = 0
  Top = 0
  Caption = 'TIC TAC TOE'
  ClientHeight = 327
  ClientWidth = 426
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object USERNAME: TLabel
    Left = 48
    Top = 96
    Width = 96
    Height = 21
    Caption = 'USERNAME: '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object PASSWORD: TLabel
    Left = 48
    Top = 192
    Width = 103
    Height = 21
    Caption = 'PASSWORD: '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object user_edit: TEdit
    Left = 80
    Top = 131
    Width = 225
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object pass_edit: TEdit
    Left = 80
    Top = 219
    Width = 225
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object login: TButton
    Left = 136
    Top = 272
    Width = 113
    Height = 33
    Caption = 'LOGIN  '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = loginClick
  end
end
