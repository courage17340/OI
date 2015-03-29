var
  a,b:array[-10..10100] of longint;
  s:ansistring;
  i,j,L:longint;
  p:qword;
begin
  readln(s);
  L:=length(s);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to L do
    a[i]:=ord(s[i])-48;
  for i:=1 to L do
    for j:=1 to L do
      b[i+j-1]:=b[i+j-1]+a[i]*a[j];
  j:=0;
  for i:=1 to L*2-1 do
    begin
      j:=b[i]+j*10;
      b[i]:=j div 4;
      j:=j mod 4;
    end;
  j:=0;
  for i:=L*2-1 downto 1 do
    begin
      b[i]:=b[i]+j;
      j:=b[i] div 10;
      b[i]:=b[i] mod 10;
    end;
  if j>0 then write(j);
  p:=1;
  if j=0 then while b[p]=0 do inc(p);
  for i:=p to L*2-1 do write(b[i]);
  if p>L*2-1 then write(0);
  writeln;
end.