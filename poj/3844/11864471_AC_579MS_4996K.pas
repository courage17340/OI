var
  a:array[1..50000] of longint;
  f:array[0..1000000] of longint;
  n,m,i,j,ans,k,p,d:longint;
begin
  readln(k);
  for p:=1 to k do
    begin
      readln(d,n);
      for i:=1 to n do read(a[i]);
      fillchar(f,sizeof(f),0);
      a[1]:=a[1] mod d;
      for i:=2 to n do a[i]:=(a[i]+a[i-1]) mod d;
      f[0]:=1;
      for i:=1 to n do inc(f[a[i]]);
      ans:=0;
      for i:=0 to d-1 do
        ans:=ans+int64(f[i])*int64((f[i]-1)) shr 1;
      writeln(ans);
    end;
end.