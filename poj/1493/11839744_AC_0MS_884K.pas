var
  a:array[1..13] of longint;
  max,n,i,j,ans:longint;
  s:string;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      max:=0;
      for i:=1 to n do
        begin
          readln(s);
          a[i]:=0;
          for j:=1 to length(s) do
            if s[j]='X' then inc(a[i]);
          if max<a[i] then max:=a[i];
        end;
      ans:=0;
      for i:=1 to n do inc(ans,max-a[i]);
      writeln(ans);
    end;
end.