const maxn=100;
type arr=array[1..maxn] of longint;
var
  a:array[0..99] of arr;
  i,j,x,y,z,p:longint;
procedure plus(q:longint);
var
  i,jw:longint;
begin
  for i:=1 to maxn do
    a[q,i]:=a[q-1,i]+a[q-2,i]+a[q-3,i];
  jw:=0;
  for i:=maxn downto 1 do
    begin
      a[q,i]:=a[q,i]+jw;
      jw:=a[q,i] div 10;
      a[q,i]:=a[q,i] mod 10;
    end;
end;
begin
  while not eof do
    begin
      readln(x,y,z);
      fillchar(a,sizeof(a),0);
      p:=maxn+1;
      while x>0 do
        begin
          dec(p);
          a[0][p]:=x mod 10;
          x:=x div 10;
        end;
      p:=maxn+1;
      while y>0 do
        begin
          dec(p);
          a[1][p]:=y mod 10;
          y:=y div 10;
        end;
      p:=maxn+1;
      while z>0 do
        begin
          dec(p);
          a[2][p]:=z mod 10;
          z:=z div 10;
        end;
      for i:=3 to 99 do plus(i);
      j:=1;
      while a[99,j]=0 do inc(j);
      for i:=j to maxn do write(a[99,i]);
      writeln;
    end;
end.