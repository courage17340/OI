var
  s:ansistring;
begin
  readln(s);readln(s);
  case s[length(s)] of
    '1','3','5','7','9':writeln('Yes');
    '0','2','4','6','8':writeln('No');
  end;
end.