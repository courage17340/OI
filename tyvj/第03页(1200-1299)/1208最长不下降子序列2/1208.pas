var
  a,Len,t:array[0..900] of longint;
  i,j,n,L,max:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do Len[i]:=1;
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
      if (a[j]>a[i])and(Len[j]>=Len[i]) then Len[i]:=Len[j]+1;
  max:=1;
  for i:=1 to n do if max<Len[i] then max:=Len[i];
  a[0]:=-maxLongint;
  Len[0]:=max+1;
  for i:=0 to n do if Len[i]=1 then t[i]:=1 eLse t[i]:=0;
  for L:=1 to max do
    begin
      for i:=n downto 1 do
        if Len[i]=L then
          begin
            j:=i-1;
            whiLe (j>=0)and(a[j]<>a[i]) do
              begin
                if (a[j]<a[i])and(Len[j]=L+1) then inc(t[j],t[i]);
                dec(j);
              end;
          end;
    end;
  writeLn(max);
  writeLn(t[0]);
end.
