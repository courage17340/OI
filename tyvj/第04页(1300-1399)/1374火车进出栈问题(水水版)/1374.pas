const size=10000;
var
  a:array[0..size] of longint;
  b:array[0..1000] of longint;
  i,j,n,m,x,k,jw:longint;
procedure print(x:longint);
begin
  if x<10 then write(0);
  if x<100 then write(0);
  if x<1000 then write(0);
  write(x);
end;
begin
  read(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  if n=1 then begin writeln(1);halt;end;
  if n=2 then begin writeln(2);halt;end;
  for i:=n+2 to n*2 do
    begin
      x:=i;
      while x>1 do
        begin
          for j:=2 to x do if x mod j=0 then break;
          inc(b[j]);
          x:=x div j;
        end;
    end;
  for i:=2 to n do
    begin
     x:=i;
      while x>1 do
        begin
          for j:=2 to x do if x mod j=0 then break;
          dec(b[j]);
          x:=x div j;
        end;
    end;
  a[size]:=1;k:=size;
  for i:=2 to 10 do
    begin
      b[i*i]:=b[i*i]+b[i] div 2;
      b[i]:=b[i] mod 2;
    end;
  for i:=2 to n*2 do
    for j:=1 to b[i] do
      begin
        jw:=0;
        for m:=size downto k do
          begin
            a[m]:=a[m]*i+jw;
            jw:=a[m] div 10000;
            a[m]:=a[m] mod 10000;
          end;
        while jw>0 do begin dec(k);a[k]:=jw mod 10000;jw:=jw div 10000;end;
      end;
  write(a[k]);
  for i:=k+1 to size do print(a[i]);
  writeln;
end.