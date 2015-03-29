var
  a,b,f:array[0..20] of longint;
  n,i,j,k:longint;
begin
  readln(k);
  for i:=1 to k do
    begin
      readln(n);
      for j:=1 to n do read(a[j]);
      a[0]:=0;
      for j:=0 to n do b[j]:=a[j]-j;
      for j:=1 to n do
        if a[j]>a[j-1] then f[j]:=1
          else
            begin
              k:=j-1;
              while b[k]>b[j] do dec(k);
              f[j]:=j-k;
            end;
      for j:=1 to n-1 do write(f[j],' ');
      writeln(f[n]);
    end;
end.