const max=110;
var
  a,b:array[1..max] of longint;
  i,k:longint;
  s:string;
procedure add;
var
  i,jw:longint;
begin
  for i:=1 to max do a[i]:=a[i]+b[i];
  jw:=0;
  for i:=max downto 1 do
    begin
      a[i]:=a[i]+jw;
      jw:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
end;
begin
  fillchar(a,sizeof(a),0);
  while true do
    begin
      readln(s);
      if s='0' then break;
      fillchar(b,sizeof(b),0);
      for i:=max downto max-length(s)+1 do
        b[i]:=ord(s[i-max+length(s)])-48;
      add;
    end;
  k:=1;
  while a[k]=0 do inc(k);
  for i:=k to max do write(a[i]);
  writeln;
end.