var
  a:array['A'..'Z'] of char;
  s:string;
  ch:char;
  i,j:longint;
function f(ch:char):char;
begin
  if ch in ['A'..'Z'] then exit(a[ch]);
  exit(ch);
end;
begin
  for ch:='F' to 'Z' do a[ch]:=chr(ord(ch)-5);
  a['A']:='V';
  a['B']:='W';
  a['C']:='X';
  a['D']:='Y';
  a['E']:='Z';
  while true do
    begin
      readln(s);
      if s[1]='E' then break;
      readln(s);
      for i:=1 to length(s) do s[i]:=f(s[i]);
      writeln(s);
      readln;
    end;
end.