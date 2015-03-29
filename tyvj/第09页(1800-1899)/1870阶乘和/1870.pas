var
  a:array[1..50,1..70] of longint;
  n,i,j,k,jw:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  a[1,70]:=1;
  k:=70;
  for i:=2 to n do
    begin
      jw:=0;
      for j:=70 downto k do a[i,j]:=a[i-1,j];
      for j:=70 downto k do
        begin
          a[i,j]:=jw+a[i,j]*i;
          jw:=a[i,j] div 10;
          a[i,j]:=a[i,j] mod 10;
        end;
      while jw>0 do
        begin
          dec(k);
          a[i,k]:=jw mod 10;
          jw:=jw div 10;
        end;
    end;
  for i:=1 to n-1 do
    begin
      jw:=0;
      for j:=70 downto k do
        begin
          a[n,j]:=a[i,j]+a[n,j]+jw;
          jw:=a[n,j] div 10;
          a[n,j]:=a[n,j] mod 10;
        end;
      while jw>0 do
        begin
          dec(k);
          a[n,k]:=jw mod 10;
          jw:=jw div 10;
        end;
    end;
  for j:=k to 70 do write(a[n,j]);
end.