var
  a,b:array[0..1601] of longint;
  i,j,m,n:longint;
  s,s1:ansistring;
  t:boolean;
procedure jia;
var
  i,jw:longint;
begin
  jw:=0;
  for i:=1600 downto n do
    begin
      a[i]:=a[i]+b[i]+jw;
      jw:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
  if jw>0 then begin dec(n);a[n]:=jw;end;
  fillchar(b,sizeof(b),0);
end;
begin
  readln(s);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  t:=true;
  n:=maxlongint;
  while t do
    begin
      m:=pos('+',s);
      if m=0 then t:=false;
      if m>0 then s1:=copy(s,1,m-1) else s1:=s;
      if n>1601-length(s1) then n:=1601-length(s1);
      delete(s,1,m);
      j:=1601;
      for i:=length(s1) downto 1 do
        begin
          dec(j);
          b[j]:=ord(s1[i])-48;
        end;
      jia;
    end;
  for i:=n to 1600 do write(a[i]);
  writeln;
end.