import gtk, gtkmozembed, urllib
import gdata.service

class YouTubeBrowser(gtk.Window):
  def __init__(self):
    gtk.Window.__init__(self)
    self.connect("destroy", gtk.main_quit)

    split = gtk.HPaned()
    self.add(split)

    self.movies = gtk.TreeView(gtk.ListStore(str, str))
    self.movies.append_column(
        gtk.TreeViewColumn("Movies", gtk.CellRendererText(), text=0))
    self.movies.connect("row-activated", self.on_row_activated)
    scroll = gtk.ScrolledWindow()
    scroll.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
    scroll.add(self.movies)

    searchbox = gtk.HBox()
    txtsearch = gtk.Entry()
    searchbox.pack_start(txtsearch, True, True)
    btnsearch = gtk.Button("Search")
    searchbox.pack_start(btnsearch, False)
    btnsearch.connect("clicked",
        lambda b: self.query(txtsearch.get_text()))

    leftside = gtk.VBox()
    leftside.pack_start(searchbox, False)
    leftside.pack_start(scroll, True)

    split.add1(leftside)

    self.browse = gtkmozembed.MozEmbed()
    split.add2(self.browse)
    self.show_all()

  def on_row_activated(self, tree, path, col):
    url = tree.get_model().get_value(tree.get_model().get_iter(path), 1)
    self.browse.load_url(url)

  def query(self, query):
    self.movies.get_model().clear()
    results =  gdata.service.GDataService(server="gdata.youtube.com").Get(
        "http://gdata.youtube.com/feeds/videos?vq=%s" %
          urllib.quote_plus(query)).entry

    for movie in results:
      title = movie.title.text
      id = movie.id.text.split("/")[-1]
      movie_url = "http://www.youtube.com/v/%s" % id

      self.movies.get_model().append([title, movie_url])

y = YouTubeBrowser()
gtk.main()