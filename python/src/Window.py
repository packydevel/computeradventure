import pygtk
pygtk.require('2.0')
import gtk

class FirstWin:
    def __init__(self):
        self.win = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.win.connect("delete_event", self.delete_event)
        self.win.connect("destroy", self.destroy)
        self.win.connect("activate-default", self.printSignal)
        self.win.connect("activate-focus", self.printSignal)
        self.win.connect("move-focus", self.printSignal)
        self.win.connect("set-focus", self.printSignal)
        #self.win.set_resizable(False)
        self.win.set_title('wow un bottone!')
        self.win.set_property("title", "new title")
        self.win.set_default_size(200, 200)
        self.icon = self.win.render_icon(gtk.STOCK_DIALOG_INFO, gtk.ICON_SIZE_BUTTON)
        self.win.set_icon(self.icon)
        self.vbox = gtk.VBox()
        self.win.add(self.vbox)
        self.button1 = gtk.Button("Quit ...")
        self.button1.connect("clicked", self.destroy)
        self.vbox.pack_start(self.button1, False, False, 5)
        self.button2 = gtk.Button("Old Label")
        self.button2.connect("clicked", self.click, "New Label")
        self.vbox.pack_start(self.button2, False, False, 5)
        self.label1 = gtk.Label("Simple Label")
        self.label2 = gtk.Label("_Label with Mnemonic")
        self.label2.set_mnemonic_widget(self.button2)
        self.label2.set_use_underline(True)
        self.label3 = gtk.Label("<b><big>Markup Label</big></b>")
        self.label3.set_use_markup(True)
        self.label4 = gtk.Label("<b><big>_Markup _Label with Mnemonic</big></b>")
        self.label4.set_use_markup(True)
        self.label4.set_use_underline(True)
        self.label5 = gtk.Label("Selectable Label")
        self.label5.set_selectable(True)
        self.button2.connect("clicked", self.printSelectedTextLabel)
        self.vbox.pack_start(self.label1, False, False, 5)
        self.vbox.pack_start(self.label2, False, False, 5)
        self.vbox.pack_start(self.label3, False, False, 5)
        self.vbox.pack_start(self.label4, False, False, 5)
        self.win.show_all()
        self.win1 = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.win1.set_default_size(200, 200)
        #self.win1.set_decorated(False);
        self.win1.move(0, 400)
        self.win1.connect("key_press_event", self.doKeyPress)
        self.table = gtk.Table(10, 10)
        self.button4 = gtk.Button('_First Button', None, True)
        self.button5 = gtk.Button(None, gtk.STOCK_OK)
        self.button6 = gtk.ToggleButton("Toggle Button")
        self.checkButton = gtk.CheckButton("Check Button", True)
        self.radioButton1 = gtk.RadioButton(None, "Radio Button 1", True)
        self.radioButton2 = gtk.RadioButton(self.radioButton1, "Radio Button 2", True)
        self.radioButton3 = gtk.RadioButton(self.radioButton1, "Radio Button 3", True)
        self.table.attach(self.button4, 1, 3, 1, 3, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.button5, 4, 6, 1, 3, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.button6, 1, 3, 5, 8, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.checkButton, 4, 6, 4, 5, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.radioButton1, 4, 6, 5, 6, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.radioButton2, 4, 6, 6, 7, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.table.attach(self.radioButton3, 4, 6, 7, 8, gtk.EXPAND, gtk.EXPAND, 2, 2)
        self.button2.connect_object("clicked", self.hideAndShow, self.win1)
        self.button2.connect("clicked", self.changeTextLabel)
        self.win1.add(self.table)
        self.win1.show_all()
    
    def printSignal(self, widget, direction=None, data=None):
        print "widget ->", widget
        print "direction ->", direction
    
    def printSelectedTextLabel(self, widget, data=None):
        print self.label5.get_selection_bounds()
    
    def changeTextLabel(self, widget, data=None):
        self.label1.set_text_with_mnemonic("_Mnemonic text Label")  
          
    def hideAndShow(self, widget, data=None):
        if widget.get_property("visible") == True:
            widget.hide()
            self.button2.grab_add()
        else:
            self.button2.grab_remove()
            widget.show()
        
    def delete_event(self, widget, event, data=None):
        return gtk.FALSE

    def destroy(self, widget, data=None):
        return gtk.main_quit()    
    
    def click(self, widget, data):
        widget.set_label(data)
        
    def doKeyPress(self, widget, event):
        keyname = gtk.gdk.keyval_name(event.keyval)
        print "the button %s was pressed" % keyname
        
    def main(self):
        gtk.main()

if __name__ == "__main__":
    first = FirstWin()
    first.main()    
