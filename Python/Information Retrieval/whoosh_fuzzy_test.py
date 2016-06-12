from whoosh.index import create_in
from whoosh.fields import *
schema = Schema(title=TEXT(stored=True), content=TEXT)
ix = create_in("indexdir", schema)
writer = ix.writer()
writer.add_document(title=u"First document", content=u"This is the first document we've added!")
writer.add_document(title=u"Second document", content=u"The second one is even more interesting!")
writer.add_document(title=u"Third document", content=u"letter first, stamp second, mail third")
writer.add_document(title=u"Fourth document", content=u"stamp first, mail third")
writer.add_document(title=u"Fivth document", content=u"letter first,  mail third")
writer.add_document(title=u"Sixth document", content=u"letters first, stamps second, mail third")
writer.add_document(title=u"Seventh document", content=u"stamp first, letters second, mial third")
writer.commit()


from whoosh.qparser import QueryParser, FuzzyTermPlugin, PhrasePlugin, SequencePlugin
with ix.searcher() as searcher:
    parser = QueryParser(u"content", ix.schema)
    parser.add_plugin(FuzzyTermPlugin())
    parser.remove_plugin_class(PhrasePlugin)
    parser.add_plugin(SequencePlugin())
    query = parser.parse(u"Apple iphone 6")
    print query
    results = searcher.search(query)
    print "nb of results =", len(results)
    for r in results:
        print r