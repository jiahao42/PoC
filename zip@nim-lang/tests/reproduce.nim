import os, osproc, streams, unittest, strutils, ../zip/zipfiles

const path = splitPath(currentSourcePath()).head & "/../zip/zipfiles"

test "can compile zipfiles":
  check execCmdEx("nim -o:./nimcache/zipfiles --nimcache:./nimcache c " &
    path).exitCode == QuitSuccess

test "zipfiles extractAll":
  var filename = "files/evil.zip"
  var z: ZipArchive
  if not z.open(filename):
    echo "Opening zip failed"
    quit(1)
  z.extractAll("files")
  z.close()

