object Menuform: TMenuform
  Left = 0
  Top = 0
  Caption = 'Menu'
  ClientHeight = 282
  ClientWidth = 384
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 88
    Top = 25
    Width = 204
    Height = 56
    Caption = 'Singleplayer'
    Font.Charset = ANSI_CHARSET
    Font.Color = clPurple
    Font.Height = -17
    Font.Name = 'Gill Sans Ultra Bold'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 103
    Width = 204
    Height = 50
    Caption = 'Multiplayer'
    Font.Charset = ANSI_CHARSET
    Font.Color = clPurple
    Font.Height = -17
    Font.Name = 'Gill Sans Ultra Bold'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 143
    Top = 233
    Width = 105
    Height = 41
    Caption = 'EXIT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clPurple
    Font.Height = -17
    Font.Name = 'Gill Sans Ultra Bold'
    Font.Style = []
    ImageAlignment = iaCenter
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 88
    Top = 175
    Width = 204
    Height = 41
    Caption = 'History'
    Font.Charset = ANSI_CHARSET
    Font.Color = clPurple
    Font.Height = -17
    Font.Name = 'Gill Sans Ultra Bold'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
end
