const
  max=1010;
var
  a,b:array[0..max] of 0..10;
  c:array[0..max*2] of integer;
  L1,L2,L:longint;
  st:ansistring;
  ch:char;
procedure init;
var
  i,k:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  st:='';
  repeat
    read(ch);
    if ch<>' ' then st:=st+ch;
    until ch=' ';
  L1:=max-length(st)+1;
  k:=0;
  for i:=L1 to max do
    begin
      inc(k);
      a[i]:=ord(st[k])-48;
    end;
  readln(st);
  L2:=max-length(st)+1;
  k:=0;
  for i:=L2 to max do
    begin
      inc(k);
      b[i]:=ord(st[k])-48;
    end;
  L:=L1+L2;
end;
procedure work;
var
  i,j:longint;
begin
  for i:=max downto L1 do
    for j:=max downto L2 do
      c[i+j]:=c[i+j]+a[i]*b[j];
  for i:=max*2 downto max*2-L do
    begin
      c[i-1]:=c[i-1]+c[i] div 10;
      c[i]:=c[i] mod 10;
    end;
  while c[L]>=10 do
    begin
      c[L-1]:=c[L] div 10;
      c[L]:=c[L] mod 10;
      dec(L);
    end;
  L:=0;while c[L]=0 do inc(L);
  for i:=L to max*2 do write(c[i]);
  writeln;
end;
begin
  init;
  work;
end.