# wxBattleship.py

import wx

########################################################################
class BattleshipPanel(wx.Panel):
    """"""

    #----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        wx.Panel.__init__(self, parent)
        
        row_sizer = wx.BoxSizer(wx.HORIZONTAL)
        
    
########################################################################
class BattleshipFrame(wx.Frame):
    """"""

    #----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        wx.Frame.__init__(self, None, title='Battleship')
        panel = BattleshipPanel(self)
        self.Show()
        
    
if __name__ == '__main__':
    app = wx.App(False)
    frame = BattleshipFrame()
    app.MainLoop()