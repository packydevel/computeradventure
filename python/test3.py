import wx

class MyFrame(wx.Frame):

    def __init__(self, parent, id):
        wx.Frame.__init__(self, parent, id, 'My first frame', size=(400,300))
        panel=wx.Panel(self)


if __name__=='__main__':
    app=wx.PySimpleApp()
    frame=MyFrame(parent=None, id=-1)
    frame.Show()
    app.MainLoop()
    del frame
    del app
