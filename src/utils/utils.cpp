#include "utils.hpp"

std::map<std::string, std::string> &ft::initilizeContentTypes()
{
	std::map<std::string, std::string> *contentType= new std::map<std::string, std::string>();
	contentType->insert(std::pair<std::string, std::string>("123", "application/vnd.lotus-1-2-3"));
	contentType->insert(std::pair<std::string, std::string>("3ds", "image/x-3ds"));
	contentType->insert(std::pair<std::string, std::string>("669", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("a", "application/x-archive"));
	contentType->insert(std::pair<std::string, std::string>("abw", "application/x-abiword"));
	contentType->insert(std::pair<std::string, std::string>("ac3", "audio/ac3"));
	contentType->insert(std::pair<std::string, std::string>("adb", "text/x-adasrc"));
	contentType->insert(std::pair<std::string, std::string>("ads", "text/x-adasrc"));
	contentType->insert(std::pair<std::string, std::string>("afm", "application/x-font-afm"));
	contentType->insert(std::pair<std::string, std::string>("ag", "image/x-applix-graphics"));
	contentType->insert(std::pair<std::string, std::string>("ai", "application/illustrator"));
	contentType->insert(std::pair<std::string, std::string>("aif", "audio/x-aiff"));
	contentType->insert(std::pair<std::string, std::string>("aifc", "audio/x-aiff"));
	contentType->insert(std::pair<std::string, std::string>("aiff", "audio/x-aiff"));
	contentType->insert(std::pair<std::string, std::string>("al", "application/x-perl"));
	contentType->insert(std::pair<std::string, std::string>("arj", "application/x-arj"));
	contentType->insert(std::pair<std::string, std::string>("as", "application/x-applix-spreadsheet"));
	contentType->insert(std::pair<std::string, std::string>("asc", "text/plain"));
	contentType->insert(std::pair<std::string, std::string>("asf", "video/x-ms-asf"));
	contentType->insert(std::pair<std::string, std::string>("asp", "application/x-asp"));
	contentType->insert(std::pair<std::string, std::string>("asx", "video/x-ms-asf"));
	contentType->insert(std::pair<std::string, std::string>("au", "audio/basic"));
	contentType->insert(std::pair<std::string, std::string>("avi", "video/x-msvideo"));
	contentType->insert(std::pair<std::string, std::string>("aw", "application/x-applix-word"));
	contentType->insert(std::pair<std::string, std::string>("bak", "application/x-trash"));
	contentType->insert(std::pair<std::string, std::string>("bcpio", "application/x-bcpio"));
	contentType->insert(std::pair<std::string, std::string>("bdf", "application/x-font-bdf"));
	contentType->insert(std::pair<std::string, std::string>("bib", "text/x-bibtex"));
	contentType->insert(std::pair<std::string, std::string>("bin", "application/octet-stream"));
	contentType->insert(std::pair<std::string, std::string>("blend", "application/x-blender"));
	contentType->insert(std::pair<std::string, std::string>("blender", "application/x-blender"));
	contentType->insert(std::pair<std::string, std::string>("bmp", "image/bmp"));
	contentType->insert(std::pair<std::string, std::string>("bz", "application/x-bzip"));
	contentType->insert(std::pair<std::string, std::string>("bz2", "application/x-bzip"));
	contentType->insert(std::pair<std::string, std::string>("c", "text/x-csrc"));
	contentType->insert(std::pair<std::string, std::string>("c++", "text/x-c++src"));
	contentType->insert(std::pair<std::string, std::string>("cc", "text/x-c++src"));
	contentType->insert(std::pair<std::string, std::string>("cdf", "application/x-netcdf"));
	contentType->insert(std::pair<std::string, std::string>("cdr", "application/vnd.corel-draw"));
	contentType->insert(std::pair<std::string, std::string>("cer", "application/x-x509-ca-cert"));
	contentType->insert(std::pair<std::string, std::string>("cert", "application/x-x509-ca-cert"));
	contentType->insert(std::pair<std::string, std::string>("cgi", "application/x-cgi"));
	contentType->insert(std::pair<std::string, std::string>("cgm", "image/cgm"));
	contentType->insert(std::pair<std::string, std::string>("chrt", "application/x-kchart"));
	contentType->insert(std::pair<std::string, std::string>("class", "application/x-java"));
	contentType->insert(std::pair<std::string, std::string>("cls", "text/x-tex"));
	contentType->insert(std::pair<std::string, std::string>("cpio", "application/x-cpio"));
	contentType->insert(std::pair<std::string, std::string>("cpp", "text/x-c++src"));
	contentType->insert(std::pair<std::string, std::string>("crt", "application/x-x509-ca-cert"));
	contentType->insert(std::pair<std::string, std::string>("cs", "text/x-csharp"));
	contentType->insert(std::pair<std::string, std::string>("csh", "application/x-shellscript"));
	contentType->insert(std::pair<std::string, std::string>("css", "text/css"));
	contentType->insert(std::pair<std::string, std::string>("cssl", "text/css"));
	contentType->insert(std::pair<std::string, std::string>("csv", "text/x-comma-separated-values"));
	contentType->insert(std::pair<std::string, std::string>("cur", "image/x-win-bitmap"));
	contentType->insert(std::pair<std::string, std::string>("cxx", "text/x-c++src"));
	contentType->insert(std::pair<std::string, std::string>("dat", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("dbf", "application/x-dbase"));
	contentType->insert(std::pair<std::string, std::string>("dc", "application/x-dc-rom"));
	contentType->insert(std::pair<std::string, std::string>("dcl", "text/x-dcl"));
	contentType->insert(std::pair<std::string, std::string>("dcm", "image/x-dcm"));
	contentType->insert(std::pair<std::string, std::string>("deb", "application/x-deb"));
	contentType->insert(std::pair<std::string, std::string>("der", "application/x-x509-ca-cert"));
	contentType->insert(std::pair<std::string, std::string>("desktop", "application/x-desktop"));
	contentType->insert(std::pair<std::string, std::string>("dia", "application/x-dia-diagram"));
	contentType->insert(std::pair<std::string, std::string>("diff", "text/x-patch"));
	contentType->insert(std::pair<std::string, std::string>("djv", "image/vnd.djvu"));
	contentType->insert(std::pair<std::string, std::string>("djvu", "image/vnd.djvu"));
	contentType->insert(std::pair<std::string, std::string>("doc", "application/vnd.ms-word"));
	contentType->insert(std::pair<std::string, std::string>("dsl", "text/x-dsl"));
	contentType->insert(std::pair<std::string, std::string>("dtd", "text/x-dtd"));
	contentType->insert(std::pair<std::string, std::string>("dvi", "application/x-dvi"));
	contentType->insert(std::pair<std::string, std::string>("dwg", "image/vnd.dwg"));
	contentType->insert(std::pair<std::string, std::string>("dxf", "image/vnd.dxf"));
	contentType->insert(std::pair<std::string, std::string>("egon", "application/x-egon"));
	contentType->insert(std::pair<std::string, std::string>("el", "text/x-emacs-lisp"));
	contentType->insert(std::pair<std::string, std::string>("eps", "image/x-eps"));
	contentType->insert(std::pair<std::string, std::string>("epsf", "image/x-eps"));
	contentType->insert(std::pair<std::string, std::string>("epsi", "image/x-eps"));
	contentType->insert(std::pair<std::string, std::string>("etheme", "application/x-e-theme"));
	contentType->insert(std::pair<std::string, std::string>("etx", "text/x-setext"));
	contentType->insert(std::pair<std::string, std::string>("exe", "application/x-ms-dos-executable"));
	contentType->insert(std::pair<std::string, std::string>("ez", "application/andrew-inset"));
	contentType->insert(std::pair<std::string, std::string>("f", "text/x-fortran"));
	contentType->insert(std::pair<std::string, std::string>("fig", "image/x-xfig"));
	contentType->insert(std::pair<std::string, std::string>("fits", "image/x-fits"));
	contentType->insert(std::pair<std::string, std::string>("flac", "audio/x-flac"));
	contentType->insert(std::pair<std::string, std::string>("flc", "video/x-flic"));
	contentType->insert(std::pair<std::string, std::string>("fli", "video/x-flic"));
	contentType->insert(std::pair<std::string, std::string>("flw", "application/x-kivio"));
	contentType->insert(std::pair<std::string, std::string>("fo", "text/x-xslfo"));
	contentType->insert(std::pair<std::string, std::string>("g3", "image/fax-g3"));
	contentType->insert(std::pair<std::string, std::string>("gb", "application/x-gameboy-rom"));
	contentType->insert(std::pair<std::string, std::string>("gcrd", "text/x-vcard"));
	contentType->insert(std::pair<std::string, std::string>("gen", "application/x-genesis-rom"));
	contentType->insert(std::pair<std::string, std::string>("gg", "application/x-sms-rom"));
	contentType->insert(std::pair<std::string, std::string>("gif", "image/gif"));
	contentType->insert(std::pair<std::string, std::string>("glade", "application/x-glade"));
	contentType->insert(std::pair<std::string, std::string>("gmo", "application/x-gettext-translation"));
	contentType->insert(std::pair<std::string, std::string>("gnc", "application/x-gnucash"));
	contentType->insert(std::pair<std::string, std::string>("gnucash", "application/x-gnucash"));
	contentType->insert(std::pair<std::string, std::string>("gnumeric", "application/x-gnumeric"));
	contentType->insert(std::pair<std::string, std::string>("gra", "application/x-graphite"));
	contentType->insert(std::pair<std::string, std::string>("gsf", "application/x-font-type1"));
	contentType->insert(std::pair<std::string, std::string>("gtar", "application/x-gtar"));
	contentType->insert(std::pair<std::string, std::string>("gz", "application/x-gzip"));
	contentType->insert(std::pair<std::string, std::string>("h", "text/x-chdr"));
	contentType->insert(std::pair<std::string, std::string>("h++", "text/x-chdr"));
	contentType->insert(std::pair<std::string, std::string>("hdf", "application/x-hdf"));
	contentType->insert(std::pair<std::string, std::string>("hh", "text/x-c++hdr"));
	contentType->insert(std::pair<std::string, std::string>("hp", "text/x-chdr"));
	contentType->insert(std::pair<std::string, std::string>("hpgl", "application/vnd.hp-hpgl"));
	contentType->insert(std::pair<std::string, std::string>("hs", "text/x-haskell"));
	contentType->insert(std::pair<std::string, std::string>("htm", "text/html"));
	contentType->insert(std::pair<std::string, std::string>("html", "text/html"));
	contentType->insert(std::pair<std::string, std::string>("icb", "image/x-icb"));
	contentType->insert(std::pair<std::string, std::string>("ico", "image/x-ico"));
	contentType->insert(std::pair<std::string, std::string>("ics", "text/calendar"));
	contentType->insert(std::pair<std::string, std::string>("idl", "text/x-idl"));
	contentType->insert(std::pair<std::string, std::string>("ief", "image/ief"));
	contentType->insert(std::pair<std::string, std::string>("iff", "image/x-iff"));
	contentType->insert(std::pair<std::string, std::string>("ilbm", "image/x-ilbm"));
	contentType->insert(std::pair<std::string, std::string>("iso", "application/x-cd-image"));
	contentType->insert(std::pair<std::string, std::string>("it", "audio/x-it"));
	contentType->insert(std::pair<std::string, std::string>("jar", "application/x-jar"));
	contentType->insert(std::pair<std::string, std::string>("java", "text/x-java"));
	contentType->insert(std::pair<std::string, std::string>("jng", "image/x-jng"));
	contentType->insert(std::pair<std::string, std::string>("jp2", "image/jpeg2000"));
	contentType->insert(std::pair<std::string, std::string>("jpe", "image/jpeg"));
	contentType->insert(std::pair<std::string, std::string>("jpeg", "image/jpeg"));
	contentType->insert(std::pair<std::string, std::string>("jpg", "image/jpeg"));
	contentType->insert(std::pair<std::string, std::string>("jpr", "application/x-jbuilder-project"));
	contentType->insert(std::pair<std::string, std::string>("jpx", "application/x-jbuilder-project"));
	contentType->insert(std::pair<std::string, std::string>("js", "application/x-javascript"));
	contentType->insert(std::pair<std::string, std::string>("karbon", "application/x-karbon"));
	contentType->insert(std::pair<std::string, std::string>("kdelnk", "application/x-desktop"));
	contentType->insert(std::pair<std::string, std::string>("kfo", "application/x-kformula"));
	contentType->insert(std::pair<std::string, std::string>("kil", "application/x-killustrator"));
	contentType->insert(std::pair<std::string, std::string>("kon", "application/x-kontour"));
	contentType->insert(std::pair<std::string, std::string>("kpm", "application/x-kpovmodeler"));
	contentType->insert(std::pair<std::string, std::string>("kpr", "application/x-kpresenter"));
	contentType->insert(std::pair<std::string, std::string>("kpt", "application/x-kpresenter"));
	contentType->insert(std::pair<std::string, std::string>("kra", "application/x-krita"));
	contentType->insert(std::pair<std::string, std::string>("ksp", "application/x-kspread"));
	contentType->insert(std::pair<std::string, std::string>("kud", "application/x-kugar"));
	contentType->insert(std::pair<std::string, std::string>("kwd", "application/x-kword"));
	contentType->insert(std::pair<std::string, std::string>("kwt", "application/x-kword"));
	contentType->insert(std::pair<std::string, std::string>("la", "application/x-shared-library-la"));
	contentType->insert(std::pair<std::string, std::string>("lha", "application/x-lha"));
	contentType->insert(std::pair<std::string, std::string>("lhs", "text/x-literate-haskell"));
	contentType->insert(std::pair<std::string, std::string>("lhz", "application/x-lhz"));
	contentType->insert(std::pair<std::string, std::string>("log", "text/x-log"));
	contentType->insert(std::pair<std::string, std::string>("ltx", "text/x-tex"));
	contentType->insert(std::pair<std::string, std::string>("lwo", "image/x-lwo"));
	contentType->insert(std::pair<std::string, std::string>("lwob", "image/x-lwo"));
	contentType->insert(std::pair<std::string, std::string>("lws", "image/x-lws"));
	contentType->insert(std::pair<std::string, std::string>("lyx", "application/x-lyx"));
	contentType->insert(std::pair<std::string, std::string>("lzh", "application/x-lha"));
	contentType->insert(std::pair<std::string, std::string>("lzo", "application/x-lzop"));
	contentType->insert(std::pair<std::string, std::string>("m", "text/x-objcsrc"));
	contentType->insert(std::pair<std::string, std::string>("m15", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("m3u", "audio/x-mpegurl"));
	contentType->insert(std::pair<std::string, std::string>("man", "application/x-troff-man"));
	contentType->insert(std::pair<std::string, std::string>("md", "application/x-genesis-rom"));
	contentType->insert(std::pair<std::string, std::string>("me", "text/x-troff-me"));
	contentType->insert(std::pair<std::string, std::string>("mgp", "application/x-magicpoint"));
	contentType->insert(std::pair<std::string, std::string>("mid", "audio/midi"));
	contentType->insert(std::pair<std::string, std::string>("midi", "audio/midi"));
	contentType->insert(std::pair<std::string, std::string>("mif", "application/x-mif"));
	contentType->insert(std::pair<std::string, std::string>("mkv", "application/x-matroska"));
	contentType->insert(std::pair<std::string, std::string>("mm", "text/x-troff-mm"));
	contentType->insert(std::pair<std::string, std::string>("mml", "text/mathml"));
	contentType->insert(std::pair<std::string, std::string>("mng", "video/x-mng"));
	contentType->insert(std::pair<std::string, std::string>("moc", "text/x-moc"));
	contentType->insert(std::pair<std::string, std::string>("mod", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("moov", "video/quicktime"));
	contentType->insert(std::pair<std::string, std::string>("mov", "video/quicktime"));
	contentType->insert(std::pair<std::string, std::string>("movie", "video/x-sgi-movie"));
	contentType->insert(std::pair<std::string, std::string>("mp2", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("mp3", "audio/x-mp3"));
	contentType->insert(std::pair<std::string, std::string>("mpe", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("mpeg", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("mpg", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("ms", "text/x-troff-ms"));
	contentType->insert(std::pair<std::string, std::string>("msod", "image/x-msod"));
	contentType->insert(std::pair<std::string, std::string>("msx", "application/x-msx-rom"));
	contentType->insert(std::pair<std::string, std::string>("mtm", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("n64", "application/x-n64-rom"));
	contentType->insert(std::pair<std::string, std::string>("nc", "application/x-netcdf"));
	contentType->insert(std::pair<std::string, std::string>("nes", "application/x-nes-rom"));
	contentType->insert(std::pair<std::string, std::string>("nsv", "video/x-nsv"));
	contentType->insert(std::pair<std::string, std::string>("o", "application/x-object"));
	contentType->insert(std::pair<std::string, std::string>("obj", "application/x-tgif"));
	contentType->insert(std::pair<std::string, std::string>("oda", "application/oda"));
	contentType->insert(std::pair<std::string, std::string>("ogg", "application/ogg"));
	contentType->insert(std::pair<std::string, std::string>("old", "application/x-trash"));
	contentType->insert(std::pair<std::string, std::string>("oleo", "application/x-oleo"));
	contentType->insert(std::pair<std::string, std::string>("p", "text/x-pascal"));
	contentType->insert(std::pair<std::string, std::string>("p12", "application/x-pkcs12"));
	contentType->insert(std::pair<std::string, std::string>("p7s", "application/pkcs7-signature"));
	contentType->insert(std::pair<std::string, std::string>("pas", "text/x-pascal"));
	contentType->insert(std::pair<std::string, std::string>("patch", "text/x-patch"));
	contentType->insert(std::pair<std::string, std::string>("pbm", "image/x-portable-bitmap"));
	contentType->insert(std::pair<std::string, std::string>("pcd", "image/x-photo-cd"));
	contentType->insert(std::pair<std::string, std::string>("pcf", "application/x-font-pcf"));
	contentType->insert(std::pair<std::string, std::string>("pcl", "application/vnd.hp-pcl"));
	contentType->insert(std::pair<std::string, std::string>("pdb", "application/vnd.palm"));
	contentType->insert(std::pair<std::string, std::string>("pdf", "application/pdf"));
	contentType->insert(std::pair<std::string, std::string>("pem", "application/x-x509-ca-cert"));
	contentType->insert(std::pair<std::string, std::string>("perl", "application/x-perl"));
	contentType->insert(std::pair<std::string, std::string>("pfa", "application/x-font-type1"));
	contentType->insert(std::pair<std::string, std::string>("pfb", "application/x-font-type1"));
	contentType->insert(std::pair<std::string, std::string>("pfx", "application/x-pkcs12"));
	contentType->insert(std::pair<std::string, std::string>("pgm", "image/x-portable-graymap"));
	contentType->insert(std::pair<std::string, std::string>("pgn", "application/x-chess-pgn"));
	contentType->insert(std::pair<std::string, std::string>("pgp", "application/pgp"));
	contentType->insert(std::pair<std::string, std::string>("php", "application/x-php"));
	contentType->insert(std::pair<std::string, std::string>("php3", "application/x-php"));
	contentType->insert(std::pair<std::string, std::string>("php4", "application/x-php"));
	contentType->insert(std::pair<std::string, std::string>("pict", "image/x-pict"));
	contentType->insert(std::pair<std::string, std::string>("pict1", "image/x-pict"));
	contentType->insert(std::pair<std::string, std::string>("pict2", "image/x-pict"));
	contentType->insert(std::pair<std::string, std::string>("pl", "application/x-perl"));
	contentType->insert(std::pair<std::string, std::string>("pls", "audio/x-scpls"));
	contentType->insert(std::pair<std::string, std::string>("pm", "application/x-perl"));
	contentType->insert(std::pair<std::string, std::string>("png", "image/png"));
	contentType->insert(std::pair<std::string, std::string>("pnm", "image/x-portable-anymap"));
	contentType->insert(std::pair<std::string, std::string>("po", "text/x-gettext-translation"));
	contentType->insert(std::pair<std::string, std::string>("pot", "text/x-gettext-translation-template"));
	contentType->insert(std::pair<std::string, std::string>("ppm", "image/x-portable-pixmap"));
	contentType->insert(std::pair<std::string, std::string>("pps", "application/vnd.ms-powerpoint"));
	contentType->insert(std::pair<std::string, std::string>("ppt", "application/vnd.ms-powerpoint"));
	contentType->insert(std::pair<std::string, std::string>("ppz", "application/vnd.ms-powerpoint"));
	contentType->insert(std::pair<std::string, std::string>("ps", "application/postscript"));
	contentType->insert(std::pair<std::string, std::string>("psd", "image/x-psd"));
	contentType->insert(std::pair<std::string, std::string>("psf", "application/x-font-linux-psf"));
	contentType->insert(std::pair<std::string, std::string>("psid", "audio/prs.sid"));
	contentType->insert(std::pair<std::string, std::string>("pw", "application/x-pw"));
	contentType->insert(std::pair<std::string, std::string>("py", "application/x-python"));
	contentType->insert(std::pair<std::string, std::string>("pyc", "application/x-python-bytecode"));
	contentType->insert(std::pair<std::string, std::string>("pyo", "application/x-python-bytecode"));
	contentType->insert(std::pair<std::string, std::string>("qif", "application/x-qw"));
	contentType->insert(std::pair<std::string, std::string>("qt", "video/quicktime"));
	contentType->insert(std::pair<std::string, std::string>("qtvr", "video/quicktime"));
	contentType->insert(std::pair<std::string, std::string>("ra", "audio/x-pn-realaudio"));
	contentType->insert(std::pair<std::string, std::string>("ram", "audio/x-pn-realaudio"));
	contentType->insert(std::pair<std::string, std::string>("rar", "application/x-rar"));
	contentType->insert(std::pair<std::string, std::string>("ras", "image/x-cmu-raster"));
	contentType->insert(std::pair<std::string, std::string>("rdf", "text/rdf"));
	contentType->insert(std::pair<std::string, std::string>("rej", "application/x-reject"));
	contentType->insert(std::pair<std::string, std::string>("rgb", "image/x-rgb"));
	contentType->insert(std::pair<std::string, std::string>("rle", "image/rle"));
	contentType->insert(std::pair<std::string, std::string>("rm", "audio/x-pn-realaudio"));
	contentType->insert(std::pair<std::string, std::string>("roff", "application/x-troff"));
	contentType->insert(std::pair<std::string, std::string>("rpm", "application/x-rpm"));
	contentType->insert(std::pair<std::string, std::string>("rss", "text/rss"));
	contentType->insert(std::pair<std::string, std::string>("rtf", "application/rtf"));
	contentType->insert(std::pair<std::string, std::string>("rtx", "text/richtext"));
	contentType->insert(std::pair<std::string, std::string>("s3m", "audio/x-s3m"));
	contentType->insert(std::pair<std::string, std::string>("sam", "application/x-amipro"));
	contentType->insert(std::pair<std::string, std::string>("scm", "text/x-scheme"));
	contentType->insert(std::pair<std::string, std::string>("sda", "application/vnd.stardivision.draw"));
	contentType->insert(std::pair<std::string, std::string>("sdc", "application/vnd.stardivision.calc"));
	contentType->insert(std::pair<std::string, std::string>("sdd", "application/vnd.stardivision.impress"));
	contentType->insert(std::pair<std::string, std::string>("sdp", "application/vnd.stardivision.impress"));
	contentType->insert(std::pair<std::string, std::string>("sds", "application/vnd.stardivision.chart"));
	contentType->insert(std::pair<std::string, std::string>("sdw", "application/vnd.stardivision.writer"));
	contentType->insert(std::pair<std::string, std::string>("sgi", "image/x-sgi"));
	contentType->insert(std::pair<std::string, std::string>("sgl", "application/vnd.stardivision.writer"));
	contentType->insert(std::pair<std::string, std::string>("sgm", "text/sgml"));
	contentType->insert(std::pair<std::string, std::string>("sgml", "text/sgml"));
	contentType->insert(std::pair<std::string, std::string>("sh", "application/x-shellscript"));
	contentType->insert(std::pair<std::string, std::string>("shar", "application/x-shar"));
	contentType->insert(std::pair<std::string, std::string>("siag", "application/x-siag"));
	contentType->insert(std::pair<std::string, std::string>("sid", "audio/prs.sid"));
	contentType->insert(std::pair<std::string, std::string>("sik", "application/x-trash"));
	contentType->insert(std::pair<std::string, std::string>("slk", "text/spreadsheet"));
	contentType->insert(std::pair<std::string, std::string>("smd", "application/vnd.stardivision.mail"));
	contentType->insert(std::pair<std::string, std::string>("smf", "application/vnd.stardivision.math"));
	contentType->insert(std::pair<std::string, std::string>("smi", "application/smil"));
	contentType->insert(std::pair<std::string, std::string>("smil", "application/smil"));
	contentType->insert(std::pair<std::string, std::string>("sml", "application/smil"));
	contentType->insert(std::pair<std::string, std::string>("sms", "application/x-sms-rom"));
	contentType->insert(std::pair<std::string, std::string>("snd", "audio/basic"));
	contentType->insert(std::pair<std::string, std::string>("so", "application/x-sharedlib"));
	contentType->insert(std::pair<std::string, std::string>("spd", "application/x-font-speedo"));
	contentType->insert(std::pair<std::string, std::string>("sql", "text/x-sql"));
	contentType->insert(std::pair<std::string, std::string>("src", "application/x-wais-source"));
	contentType->insert(std::pair<std::string, std::string>("stc", "application/vnd.sun.xml.calc.template"));
	contentType->insert(std::pair<std::string, std::string>("std", "application/vnd.sun.xml.draw.template"));
	contentType->insert(std::pair<std::string, std::string>("sti", "application/vnd.sun.xml.impress.template"));
	contentType->insert(std::pair<std::string, std::string>("stm", "audio/x-stm"));
	contentType->insert(std::pair<std::string, std::string>("stw", "application/vnd.sun.xml.writer.template"));
	contentType->insert(std::pair<std::string, std::string>("sty", "text/x-tex"));
	contentType->insert(std::pair<std::string, std::string>("sun", "image/x-sun-raster"));
	contentType->insert(std::pair<std::string, std::string>("sv4cpio", "application/x-sv4cpio"));
	contentType->insert(std::pair<std::string, std::string>("sv4crc", "application/x-sv4crc"));
	contentType->insert(std::pair<std::string, std::string>("svg", "image/svg+xml"));
	contentType->insert(std::pair<std::string, std::string>("swf", "application/x-shockwave-flash"));
	contentType->insert(std::pair<std::string, std::string>("sxc", "application/vnd.sun.xml.calc"));
	contentType->insert(std::pair<std::string, std::string>("sxd", "application/vnd.sun.xml.draw"));
	contentType->insert(std::pair<std::string, std::string>("sxg", "application/vnd.sun.xml.writer.global"));
	contentType->insert(std::pair<std::string, std::string>("sxi", "application/vnd.sun.xml.impress"));
	contentType->insert(std::pair<std::string, std::string>("sxm", "application/vnd.sun.xml.math"));
	contentType->insert(std::pair<std::string, std::string>("sxw", "application/vnd.sun.xml.writer"));
	contentType->insert(std::pair<std::string, std::string>("sylk", "text/spreadsheet"));
	contentType->insert(std::pair<std::string, std::string>("t", "application/x-troff"));
	contentType->insert(std::pair<std::string, std::string>("tar", "application/x-tar"));
	contentType->insert(std::pair<std::string, std::string>("tcl", "text/x-tcl"));
	contentType->insert(std::pair<std::string, std::string>("tcpalette", "application/x-terminal-color-palette"));
	contentType->insert(std::pair<std::string, std::string>("tex", "text/x-tex"));
	contentType->insert(std::pair<std::string, std::string>("texi", "text/x-texinfo"));
	contentType->insert(std::pair<std::string, std::string>("texinfo", "text/x-texinfo"));
	contentType->insert(std::pair<std::string, std::string>("tga", "image/x-tga"));
	contentType->insert(std::pair<std::string, std::string>("tgz", "application/x-compressed-tar"));
	contentType->insert(std::pair<std::string, std::string>("theme", "application/x-theme"));
	contentType->insert(std::pair<std::string, std::string>("tif", "image/tiff"));
	contentType->insert(std::pair<std::string, std::string>("tiff", "image/tiff"));
	contentType->insert(std::pair<std::string, std::string>("tk", "text/x-tcl"));
	contentType->insert(std::pair<std::string, std::string>("torrent", "application/x-bittorrent"));
	contentType->insert(std::pair<std::string, std::string>("tr", "application/x-troff"));
	contentType->insert(std::pair<std::string, std::string>("ts", "application/x-linguist"));
	contentType->insert(std::pair<std::string, std::string>("tsv", "text/tab-separated-values"));
	contentType->insert(std::pair<std::string, std::string>("ttf", "application/x-font-ttf"));
	contentType->insert(std::pair<std::string, std::string>("txt", "text/plain"));
	contentType->insert(std::pair<std::string, std::string>("tzo", "application/x-tzo"));
	contentType->insert(std::pair<std::string, std::string>("ui", "application/x-designer"));
	contentType->insert(std::pair<std::string, std::string>("uil", "text/x-uil"));
	contentType->insert(std::pair<std::string, std::string>("ult", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("uni", "audio/x-mod"));
	contentType->insert(std::pair<std::string, std::string>("uri", "text/x-uri"));
	contentType->insert(std::pair<std::string, std::string>("url", "text/x-uri"));
	contentType->insert(std::pair<std::string, std::string>("ustar", "application/x-ustar"));
	contentType->insert(std::pair<std::string, std::string>("vcf", "text/x-vcalendar"));
	contentType->insert(std::pair<std::string, std::string>("vcs", "text/x-vcalendar"));
	contentType->insert(std::pair<std::string, std::string>("vct", "text/x-vcard"));
	contentType->insert(std::pair<std::string, std::string>("vob", "video/mpeg"));
	contentType->insert(std::pair<std::string, std::string>("voc", "audio/x-voc"));
	contentType->insert(std::pair<std::string, std::string>("vor", "application/vnd.stardivision.writer"));
	contentType->insert(std::pair<std::string, std::string>("vpp", "application/x-extension-vpp"));
	contentType->insert(std::pair<std::string, std::string>("wav", "audio/x-wav"));
	contentType->insert(std::pair<std::string, std::string>("wb1", "application/x-quattropro"));
	contentType->insert(std::pair<std::string, std::string>("wb2", "application/x-quattropro"));
	contentType->insert(std::pair<std::string, std::string>("wb3", "application/x-quattropro"));
	contentType->insert(std::pair<std::string, std::string>("wk1", "application/vnd.lotus-1-2-3"));
	contentType->insert(std::pair<std::string, std::string>("wk3", "application/vnd.lotus-1-2-3"));
	contentType->insert(std::pair<std::string, std::string>("wk4", "application/vnd.lotus-1-2-3"));
	contentType->insert(std::pair<std::string, std::string>("wks", "application/vnd.lotus-1-2-3"));
	contentType->insert(std::pair<std::string, std::string>("wmf", "image/x-wmf"));
	contentType->insert(std::pair<std::string, std::string>("wml", "text/vnd.wap.wml"));
	contentType->insert(std::pair<std::string, std::string>("wmv", "video/x-ms-wmv"));
	contentType->insert(std::pair<std::string, std::string>("wpd", "application/vnd.wordperfect"));
	contentType->insert(std::pair<std::string, std::string>("wpg", "application/x-wpg"));
	contentType->insert(std::pair<std::string, std::string>("wri", "application/x-mswrite"));
	contentType->insert(std::pair<std::string, std::string>("wrl", "model/vrml"));
	contentType->insert(std::pair<std::string, std::string>("xac", "application/x-gnucash"));
	contentType->insert(std::pair<std::string, std::string>("xbel", "application/x-xbel"));
	contentType->insert(std::pair<std::string, std::string>("xbm", "image/x-xbitmap"));
	contentType->insert(std::pair<std::string, std::string>("xcf", "image/x-xcf"));
	contentType->insert(std::pair<std::string, std::string>("xhtml", "application/xhtml+xml"));
	contentType->insert(std::pair<std::string, std::string>("xi", "audio/x-xi"));
	contentType->insert(std::pair<std::string, std::string>("xla", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xlc", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xld", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xll", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xlm", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xls", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xlt", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xlw", "application/vnd.ms-excel"));
	contentType->insert(std::pair<std::string, std::string>("xm", "audio/x-xm"));
	contentType->insert(std::pair<std::string, std::string>("xmi", "text/x-xmi"));
	contentType->insert(std::pair<std::string, std::string>("xml", "text/xml"));
	contentType->insert(std::pair<std::string, std::string>("xpm", "image/x-xpixmap"));
	contentType->insert(std::pair<std::string, std::string>("xsl", "text/x-xslt"));
	contentType->insert(std::pair<std::string, std::string>("xslfo", "text/x-xslfo"));
	contentType->insert(std::pair<std::string, std::string>("xslt", "text/x-xslt"));
	contentType->insert(std::pair<std::string, std::string>("xwd", "image/x-xwindowdump"));
	contentType->insert(std::pair<std::string, std::string>("z", "application/x-compress"));
	contentType->insert(std::pair<std::string, std::string>("zabw", "application/x-abiword"));
	contentType->insert(std::pair<std::string, std::string>("zip", "application/zip"));
	contentType->insert(std::pair<std::string, std::string>("zoo", "application/x-zoo"));
	return *contentType;
}
