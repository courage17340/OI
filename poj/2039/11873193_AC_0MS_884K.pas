var
  a:array[1..100,1..20] of char;
  s,t:string;
  n,i,j,k:longint;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      readln(s);
      j:=0;
      k:=1;
      while s<>'' do
        begin
          inc(j);
          if k=1 then for i:=1 to n do a[j,i]:=s[i] else for i:=1 to n do a[j,i]:=s[n+1-i];
          k:=1-k;
          delete(s,1,n);
        end;
      k:=j;
      t:='';
      for j:=1 to n do
        for i:=1 to k do
          t:=t+a[i,j];
      writeln(t);
    end;
end.