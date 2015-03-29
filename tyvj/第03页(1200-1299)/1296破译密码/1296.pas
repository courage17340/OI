var
  s:ansistring;
  f:array['0'..'9'] of longint;
  n,sec,i:longint;
  ch:char;
begin
  readln(s);
  readln(n);
  sec:=(ord(s[1])-48) xor n;
  for ch:='0' to '9' do
    f[ch]:=((ord(ch)-48) xor sec) mod 10;
  for i:=1 to length(s) do write(f[s[i]]);writeln;
end.